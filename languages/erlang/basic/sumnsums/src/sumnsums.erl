-module(sumnsums).

-export([main/1]).

strlist_to_intlist(Str_List) ->
    lists:map(fun (Elem) -> {Num, _} = string:to_integer(Elem), Num end, Str_List).

main(Args) ->
    A = 3,
    Int_Args = strlist_to_intlist(Args),
    io:format("The list of strs from command line: ~p ~n", [Args]),
    io:format("The list of ints: ~w~n", [Int_Args]),
    io:format("Sum of all the ints is: ~p!~n", [lists:sum(Int_Args)]),
    io:format("BTW, the variable is ~p! ~n", [A]).