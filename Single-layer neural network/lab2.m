% 重新导入训练集
trainLabels = trainLabels(1:1000);
trainData = trainData(1:1000, :);


% 计算每个数字的样本数量
num_of_sample = zeros(1, 10);  % 初始化每个数字的样本数量为零

for i = 0:9
    num_of_sample(i+1) = sum(trainLabels == i);
end

% 显示特定数字的样本图像
digit = 2;  % 要显示的数字

% 找到训练集中标签等于指定数字的样本索引
digit_indices = find(trainLabels == digit);

% 显示所有样本
figure;
for i = 1:length(digit_indices)
    imageData = trainData(digit_indices(i), :);
    imageMatrix = reshape(imageData, 28, 28)';
    subplot(ceil(sqrt(length(digit_indices))), ceil(sqrt(length(digit_indices))), i);
    imshow(imageMatrix);
    %title(num2str(i));
end

