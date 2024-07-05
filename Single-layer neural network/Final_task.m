% Load data
[train_data, test_data] = load_data();

% Set learning rate
learning_rate1 = 0.00005;
learning_rate2 = 0.00001;

% Generating weight
rng(42);
initial_weights1 = 2 * rand(1, 784) - 1;
initial_weights2 = 2 * rand(1, 784) - 1;

% Training model
[weights1, bias1, misclassified_curve1] = perceptron(train_data, learning_rate1, initial_weights1);
[weights2, bias2, misclassified_curve2] = perceptron(train_data, learning_rate2, initial_weights1);
[weights3, bias3, misclassified_curve3] = perceptron(train_data, learning_rate1, initial_weights2);
[weights4, bias4, misclassified_curve4] = perceptron(train_data, learning_rate2, initial_weights2);

% Plot an error rate curve
figure;
subplot(2, 2, 1);
plot(1:length(misclassified_curve1), misclassified_curve1, 'r-', 'LineWidth', 2);
title('Learning Rate 0.00005, Weights 1');
xlabel('Epoch');
ylabel('Misclassified Rate');

subplot(2, 2, 2);
plot(1:length(misclassified_curve2), misclassified_curve2, 'g-', 'LineWidth', 2);
title('Learning Rate 0.00003, Weights 1');
xlabel('Epoch');
ylabel('Misclassified Rate');

subplot(2, 2, 3);
plot(1:length(misclassified_curve3), misclassified_curve3, 'b-', 'LineWidth', 2);
title('Learning Rate 0.00005, Weights 2');
xlabel('Epoch');
ylabel('Misclassified Rate');

subplot(2, 2, 4);
plot(1:length(misclassified_curve4), misclassified_curve4, 'k-', 'LineWidth', 2);
title('Learning Rate 0.00003, Weights 2');
xlabel('Epoch');
ylabel('Misclassified Rate');

% Test model
weights = [weights1; weights2; weights3; weights4];
bias = [bias1, bias2, bias3, bias4];
misclassified_rate = zeros(1: 4);

for i = 1:4
    test_data_predict = predict(weights(i, :), bias(i), test_data(:, 1:end-1));
    misclassified_count = sum(test_data_predict ~= test_data(:, end));
    misclassified_rate(i) = misclassified_count / size(test_data, 1);
    disp(['NO.', num2str(i), ' Model test error rate: ', num2str(misclassified_rate(i))]);
end

% Define the loading data and preprocessing model
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

    % Set the label categories to 1 and -1
    train_data(:, end+1) = trainLabels;
    test_data(:, end+1) = testLabels;
    train_data(train_data(:, end) == 6, end) = 1;
    train_data(train_data(:, end) ~= 1, end) = -1;
    test_data(test_data(:, end) == 6, end) = 1;
    test_data(test_data(:, end) ~= 1, end) = -1;

    % Take some data for training and testing
    train_data = train_data(1:1500, :);
    test_data = test_data(1:500, :);
end

% Define the model training function
function [weights, bias, misclassified_curve] = perceptron(train_data, learning_rate, initial_weights)
    
    %Parameter setting
    weights = initial_weights; % Initial weight assignment
    bias = 0; % Initial bias
    epoch = 1; % Iteration rounds
    max_epoch = 1000; % Maximum number of iteration rounds
    min_threshold = 0.001; % Minimum error rate threshold
    misclassified_curve = []; % Model error rate curve

    while epoch <= max_epoch
        misclassified_count = 0; % Number of misclassification

        for i = 1:size(train_data, 1)
            input = train_data(i, 1:end-1)';
            label = train_data(i, end); % Expected value
            prediction = sign(weights*input + bias); % Actual value

            if prediction ~= label
                weights = weights + learning_rate * (label-prediction) * train_data(i, 1:end-1); % Weight updating
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

% Define model test functions
function prediction = predict(weights, bias, data)
    prediction = zeros(size(data,1), 1);
    
    for i = 1:size(data, 1)
        input = data(i, :)';
        output = sign(weights*input + bias); 
        prediction(i) = output;
    end
end
