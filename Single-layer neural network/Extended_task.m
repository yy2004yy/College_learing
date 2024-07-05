% Load and preprocess the data
[train_data, test_data] = load_data();

% Initialize the weights and learning rate
rng(42);
initial_weights =  2 * rand(1, 784) - 1;
learning_rate = 0.01;

% Train the models
[weights1, bias1, ~] = perceptron1(train_data, learning_rate, initial_weights);
[weights2, bias2, ~] = perceptron2(train_data, learning_rate, initial_weights);

% Test the model
prediction = predict(weights1, bias1, weights2, bias2, test_data(:, 1:end-2));
labels = test_data(:, end-1:end);

% Calculate the error rate
num_correct = sum(all(prediction == labels, 2));
error_rate = 1 - num_correct / size(prediction, 1);

% Print the original size and predicted label for each data point
for i = 1:size(test_data, 1)
    fprintf('Data: %d, Original Label: [%s], Predicted Label: [%s]\n', i, num2str(test_data(i,end-1:end)), num2str(prediction(i,:)));
end

fprintf('Error Rate: %.2f%%\n', error_rate * 100);

% Set the read data function
function [train_data, test_data] = load_data()
    % Read training labels
    fid = fopen(fullfile('.', 'train-labels.idx1-ubyte'), 'rb');
    trainLabels = fread(fid, inf, 'uint8', 'l');
    trainLabels = trainLabels(9:end);
    fclose(fid);

    % Read test labels
    fid = fopen(fullfile('.', 't10k-labels.idx1-ubyte'), 'rb');
    testLabels = fread(fid, inf, 'uint8', 'l');
    testLabels = testLabels(9:end);
    fclose(fid);

    % Read training images
    fid = fopen(fullfile('.', 'train-images.idx3-ubyte'), 'rb');
    trainImages = fread(fid, inf, 'uint8', 'l');
    trainImages = trainImages(17:end);
    fclose(fid);

    % Read test images
    fid = fopen(fullfile('.', 't10k-images.idx3-ubyte'), 'rb');
    testImages = fread(fid, inf, 'uint8', 'l');
    testImages = testImages(17:end);
    fclose(fid);

    % The image matrix is expanded into a one-dimensional vector
    train_data = reshape(trainImages, 784, size(trainImages, 1) / 784)';
    test_data = reshape(testImages, 784, size(testImages, 1) / 784)';

    % Data normalization maps pixel values between [0, 1]
    train_data = double(train_data) / 255;
    test_data = double(test_data) / 255;

    train_labels = zeros(size(trainLabels, 1), 2);
    idx = trainLabels == 0 | trainLabels == 1;
    train_labels(idx, :) = repmat([1, 1], sum(idx), 1);
    idx = trainLabels == 2 | trainLabels == 3;
    train_labels(idx, :) = repmat([1, -1], sum(idx), 1);
    idx = trainLabels == 4 | trainLabels == 5 | trainLabels == 6;
    train_labels(idx, :) = repmat([-1, 1], sum(idx), 1);
    idx = trainLabels == 7 | trainLabels == 8 | trainLabels == 9;
    train_labels(idx, :) = repmat([-1, -1], sum(idx), 1);
    
    test_labels = zeros(size(testLabels, 1), 2);
    idx = testLabels == 0 | testLabels == 1;
    test_labels(idx, :) = repmat([1, 1], sum(idx), 1);
    idx = testLabels == 2 | testLabels == 3;
    test_labels(idx, :) = repmat([1, -1], sum(idx), 1);
    idx = testLabels == 4 | testLabels == 5 | testLabels == 6;
    test_labels(idx, :) = repmat([-1, 1], sum(idx), 1);
    idx = testLabels == 7 | testLabels == 8 | testLabels == 9;
    test_labels(idx, :) = repmat([-1, -1], sum(idx), 1);

    train_data = horzcat(train_data, train_labels);
    test_data = horzcat(test_data, test_labels);

    % Take some data for training and testing
    train_data = train_data(1:10000, :);
    test_data = test_data(1:500, :);
end

% Define the model training function
function [weights, bias, misclassified_curve] = perceptron1(train_data, learning_rate, initial_weights)
    
    % Parameter setting
    weights = initial_weights; % Initial weight assignment
    bias = 0; % Initial bias
    epoch = 1; % Iteration rounds
    max_epoch = 1000; % Maximum number of iteration rounds
    min_threshold = 0.001; % Minimum error rate threshold
    misclassified_curve = []; % Model error rate curve

    while epoch <= max_epoch
        misclassified_count = 0; % Number of misclassification

        for i = 1:size(train_data, 1)
            input = train_data(i, 1:end-2)';
            label = train_data(i, end-1); % Expected value
            prediction = sign(weights*input + bias); % Actual value

            if prediction ~= label
                weights = weights + learning_rate * (label-prediction) * train_data(i, 1:end-2); % Weight updating
                bias = bias + learning_rate * (label-prediction); % Bias updating
                misclassified_count = misclassified_count + 1; % Count the number of errors
            end
        end

        misclassified_rate = misclassified_count / size(train_data, 1); % Error rate calculation
        misclassified_curve = [misclassified_curve, misclassified_rate];

        if misclassified_rate <= min_threshold % Threshold bounce
            break;
        end

        epoch = epoch + 1; 
    end
end

% Define the model training function
function [weights, bias, misclassified_curve] = perceptron2(train_data, learning_rate, initial_weights)
    
    % Parameter setting
    weights = initial_weights; % Initial weight assignment
    bias = 0; % Initial bias
    epoch = 1; % Iteration rounds
    max_epoch = 1000; % Maximum number of iteration rounds
    min_threshold = 0.001; % Minimum error rate threshold
    misclassified_curve = []; % Model error rate curve

    while epoch <= max_epoch
        misclassified_count = 0; % Number of misclassification

        for i = 1:size(train_data, 1)
            input = train_data(i, 1:end-2)';
            label = train_data(i, end); % Expected value
            prediction = sign(weights*input + bias); % Actual value

            if prediction ~= label
                weights = weights + learning_rate * (label-prediction) * train_data(i, 1:end-2); % Weight updating
                bias = bias + learning_rate * (label-prediction); % Bias updating
                misclassified_count = misclassified_count + 1; % Count the number of errors
            end
        end

        misclassified_rate = misclassified_count / size(train_data, 1); % Error rate calculation
        misclassified_curve = [misclassified_curve, misclassified_rate];

        if misclassified_rate <= min_threshold % Threshold bounce
            break;
        end

        epoch = epoch + 1; 
    end
end

% Test function design
function prediction = predict(weights1, bias1, weights2, bias2, data)
    prediction = zeros(size(data,1), 2); % Store my two-dimensional vector label
    
    for i = 1:size(data, 1)
        input = data(i, :)';

        output1 = sign(weights1*input + bias1); % Output of the first perceptron
        
        if output1 == 1
            prediction(i, 1) = 1; % Label 1, 2 (0, 1, 2, 3)

            output2 = sign(weights2*input + bias2); % Output of the second perceptron
            
            if output2 == 1
                prediction(i, 2) = 1; % Label 1, 3 (0, 1, 4, 5 ,6)
            elseif output2 == -1
                prediction(i, 2) = -1; % Label 2, 4 (2, 3, 7, 8, 9)
            end


        elseif output1 == -1
            prediction(i, 1) = -1; % Label 3, 4 (4, 5, 6, 7, 8, 9)
            
            output2 = sign(weights2*input + bias2); % Output of the second perceptron
            
            if output2 == 1
                prediction(i, 2) = 1; % Label 1, 3 (0, 1, 4, 5 ,6)
            elseif output2 == -1
                prediction(i, 2) = -1; % Label 2, 4 (2, 3, 7, 8, 9)
            end
        end
    end
end
