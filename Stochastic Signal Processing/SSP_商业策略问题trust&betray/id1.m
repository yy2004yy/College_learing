% Print your student ID and Name here, for example
% 000001    张桂嘉
%%
% your_strategy returns your strategy of the trade this time
% your_strategy = 0 means that you want to trust the counterparty this time
% your_strategy not equal to 0 means that you want to betray the
% counterparty this time 
%%
% counterparty_id is the ID of the counterparty you are going to trade with
% this time
function [your_strategy] = id1(counterparty_id)
    your_strategy = 0;  % this strategy means that you will always trust anyone 
end