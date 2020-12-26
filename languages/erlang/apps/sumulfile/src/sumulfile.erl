-module(sumulfile).

-export([main/1]).

manipulate(Ints) -> lists:foldl(fun(E, Sum) -> E + Sum end, 0, lists:map(fun(Elem) -> Elem * 2 end, Ints)).

file_to_ints(Filename) -> 
    {ok, Data} = file:read_file(Filename),
    lists:map(fun(B) -> binary_to_integer(B) end, binary:split(Data, [<<"\n">>], [global, trim])).

main([Filename]) ->
    io:format("Read ints.txt -> to list of ints -> each elem *2 -> sum up the resulting list: ~p~n", [manipulate(file_to_ints(Filename))]).
