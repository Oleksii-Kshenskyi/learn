-module(sumnsums).

-export([main/1]).

strlist_to_intlist(Str_List) ->
    lists:map(fun (Elem) -> {Num, _} = string:to_integer(Elem), Num end, Str_List).

sum_of_nth_sums([]) -> 0;
sum_of_nth_sums(Int_List) ->
    Current_Sum = lists:sum(Int_List),
    [_|Tail] = Int_List,
    Current_Sum + sum_of_nth_sums(Tail).

main(Args) ->
    Int_Args = strlist_to_intlist(Args),
    io:format("The list of strs from command line: ~p ~n", [Args]),
    io:format("The list of ints: ~w~n", [Int_Args]),
    io:format("SUM OF NTH SUMS ALREADY POGOMEGA?! => [~p]~n", [sum_of_nth_sums(Int_Args)]).