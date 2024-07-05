% Print your student ID and Name here, for example
% 2022280380 杨烨
%%
% your_strategy returns your strategy of the trade this time
% your_strategy = 0 means that you want to trust the counterparty this time
% your_strategy not equal to 0 means that you want to betray the
% counterparty this time 
%%
% counterparty_id is the ID of the counterparty you are going to trade with
% this time
function [your_strategy] = id17(counterparty_id)
    load storage_id17.mat
    load infor_id17.mat

    if counterparty_action == 1
        random_num = randi([1, 3]); % Generate a random number: 1, 2, or 3
        
        if random_num == 1
            your_strategy = 1; % This means that you have 1/3 probability to betray this person
        elseif random_num == 2
            your_strategy = 0; % This means that you have 1/3 probability to trust this person
        else
            your_strategy = -1; % This means that you have 1/3 probability to reject this person
        end
    else
        your_strategy = 0; % This means that you will trust this person
    end

    Trade_no = Trade_no + 1;

    save('storage_id21', 'Trade_no', 'your_id')
    % your strategy will trust one person and then betray one and goes on
    % ONLY save your data in the file storage_id21.mat, 
    % otherwise you will be treated as 'homework not submitted'
end
