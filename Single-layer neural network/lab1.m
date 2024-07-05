% 读取训练标签
fid = fopen(fullfile('.', 'train-labels.idx1-ubyte'), 'rb');
trainLabels = fread(fid, inf, 'uint8', 'l');
trainLabels = trainLabels(9:end);
fclose(fid);

% 读取测试标签
fid = fopen(fullfile('.', 't10k-labels.idx1-ubyte'), 'rb');
testLabels = fread(fid, inf, 'uint8', 'l');
testLabels = testLabels(9:end);
fclose(fid);

% 读取训练图像
fid = fopen(fullfile('.', 'train-images.idx3-ubyte'), 'rb');
trainImages = fread(fid, inf, 'uint8', 'l');
trainImages = trainImages(17:end);
fclose(fid);
trainData = reshape(trainImages, 784, size(trainImages, 1) / 784)';

% 读取测试图像
fid = fopen(fullfile('.', 't10k-images.idx3-ubyte'), 'rb');
testImages = fread(fid, inf, 'uint8', 'l');
testImages = testImages(17:end);
fclose(fid);
testData = reshape(testImages, 784, size(testImages, 1) / 784)';

% 将训练图像和标签组合在一起
trainDataWithLabels = [trainData, trainLabels];

figure;
for i = 1:10
    % 提取第 i 个图像数据
    imageData = trainData(i, :);
    
    % 将图像数据重新形状为 28x28 大小的矩阵
    imageMatrix = reshape(imageData, 28, 28)';

    % 在子图中显示图像
    subplot(2, 5, i);
    imshow(imageMatrix);
    title(num2str(i));
end