-module(sumnsums).

-export([main/1]).

strlist_to_intlist(Str_List) ->
    lists:map(fun (Elem) -> {Num, _} = string:to_integer(Elem), Num end, Str_List).

sum_of_nth_sums([]) -> 0;
sum_of_nth_sums(Int_List) ->
    lists:sum(Int_List) + sum_of_nth_sums(lists:droplast(Int_List)).

main(Args) ->
    Int_Args = strlist_to_intlist(Args),
    io:format("SUM OF NTH SUMS ALREADY POGOMEGA?! => [~p]~n", [sum_of_nth_sums(Int_Args)]).