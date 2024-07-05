clear;
clc;
% the above two commands clear all the previous record in the Memory

Repeated_trails = 20;                        % repeat the game Repeated_trails times
N_trades = 20;                              % trade N_trades times
N_persons = 30;                             % totally N_persons persons
N_persons_pairs = round(N_persons/2);       % N_persons_pairs groups

X_betray_trust_point = 4;
Y_betray_betray_point = 5;

Winning_numbers_in_one_game = 5;            % assume that the first 5 persons win in this game
ranking_result_total = zeros(N_persons, 1); % store the result of all the games

for n_re_tr = 1:Repeated_trails
    n_re_tr
    counterparty_list = ones(N_persons, 1);     % the counterparty list of all persons this time
    Strategies_one_trade = zeros(N_persons, 1); % the strategy of all persons this time
    Return_one_trade = zeros(N_persons, 1);     % the retrun of all persons this time
    Return_total = zeros(N_persons, 1);         % the retrun of all persons after N_trades times
    creat_storage(N_persons);                   % create all the ��storage_idXX.mat�� 
    for n_trade = 1 : N_trades                  % looping
%         n_trade                                 % just to show the trade no for quick check
        Trade_target_pairs = randperm(N_persons)';      % make a permutation of all 40 persons, from ID 1 to 40 randomly
        %% decide the trade counterparties of this time
        [Trade_list,Trade_index] = sort(Trade_target_pairs);
        for person_id = 1:N_persons
            ranking = Trade_index(person_id);
            if mod(ranking,2)==0
                counterparty_ranking = ranking - 1;
            else
                counterparty_ranking = ranking + 1;
            end
            counterparty_list(person_id) = Trade_target_pairs(counterparty_ranking);
        end
        %% run the Strategies of all the persons
        % One can only get the ID of his counterparty as the input. 
        % However, when deciding your Strategy, you can store previous results
        % for your reference, I will give examples later.
        Strategies_one_trade = Run_Strategies(counterparty_list);
        %% evaluate the Strategies, and calculate the points all persons get
        for person_id = 1:N_persons
            Strategy_this = Strategies_one_trade(person_id);
            Strategy_counterparty = Strategies_one_trade(counterparty_list(person_id));
            if Strategy_this==0
                if Strategy_counterparty==0
                    Return_one_trade(person_id) = 10;   % both trust, add 10 points
                elseif Strategy_counterparty>0
                    Return_one_trade(person_id) = -X_betray_trust_point;   % self trust, counterparty betray, -X = -6 points
                else
                    Return_one_trade(person_id) = 0;    % self trust, counterparty reject, 0 points
                end
            elseif Strategy_this>0
                if Strategy_counterparty==0
                    Return_one_trade(person_id) = 2*X_betray_trust_point;   % self betray, counterparty trust, + 2 * X = 12 points
                elseif Strategy_counterparty>0
                    Return_one_trade(person_id) = -Y_betray_betray_point;    % self betray, counterparty betray, -Y = -0 points
                else
                    Return_one_trade(person_id) = 0;    % self betray, counterparty reject, 0 points
                end
            else    % self reject, always 0 points, no matter what counterparty action is
                Return_one_trade(person_id) = 0;
            end
        end
        Return_total = Return_total + Return_one_trade; % update the return of all persons
        %% 
        % here you will be given your counterparty id and his behaviour
        % information of this time for your future references
        for person_id=1:N_persons
            filename=['infor_id',num2str(person_id)];
    %         eval([filename,'=person_id']);
            counterparty_id = counterparty_list(person_id);
            counterparty_action = Strategies_one_trade(counterparty_id);
            save(filename, 'counterparty_id', 'counterparty_action');
        end
    end
    [Return_total_list,Return_total_index] = sort(Return_total, 'descend');
    
    ranking_result = zeros(N_persons, 1);
    ranking_result(Return_total_index(1:Winning_numbers_in_one_game)) = 1;
    ranking_result_total = ranking_result_total + ranking_result;
end

% bar(Return_total)
bar(ranking_result_total)
xlim([0,31])