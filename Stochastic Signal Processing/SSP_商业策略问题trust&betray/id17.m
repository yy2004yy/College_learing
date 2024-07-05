% Print your student ID and Name here, for example
% 2022280380    杨烨
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

    if counterparty_action == 0
        your_strategy = 0;  % this means that you will trust this person
    elseif counterparty_action > 0
        your_strategy = 1;  % this means that you will betray this person
    else
        your_strategy = -1;  % this means that you will reject this person
    end
    % This person's strategy is: 
    % if get trusted last time, trust this person
    % if get betrayed last time, trust this person
    % if not, reject this person
    
    Trade_no = Trade_no + 1;

    save('storage_id17', 'Trade_no', 'your_id')
    % your strategy will trush one person and then betray one and goes on
    % ONLY save your data in the file storage_id21.mat, 
    % otherwise you will be treated as 'homework not submitted'
end