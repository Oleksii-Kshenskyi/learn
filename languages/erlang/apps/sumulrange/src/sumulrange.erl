-module(sumulrange).

-export([main/1]).

process(Ints) -> lists:foldl(fun(E, Sum) -> E + Sum end, 0, lists:map(fun(Elem) -> Elem * 2 end, Ints)).

generate_ints_and_process(UpperBound) -> 
    process(lists:seq(1, UpperBound)).

main([UpperBound]) ->
    UBInt = list_to_integer(UpperBound),
    io:format("Create range 1 .. ~B -> to list of ints -> each elem *2 -> sum up the resulting list: ~p~n", [UBInt, generate_ints_and_process(UBInt)]).
