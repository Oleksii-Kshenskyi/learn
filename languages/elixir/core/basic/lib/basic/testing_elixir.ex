defmodule Basic.PlayingWithElixir do
  def hello, do: IO.puts "Hello Elixir World!"
  def hello(name) do
    IO.puts "Hello #{name}!"
  end

  def greet(name) do
    IO.puts "Hello #{name}!"
  end

  def string_list_to_int_list(string_list) do
    string_list |> Enum.map(&String.to_integer/1)
  end

  def reduce_int_list_by_sum(int_list) do
    int_list |> Enum.reduce(fn x, acc -> acc + x end)
  end

  def sum_int_list([]), do: 0
  def sum_int_list([head|tail]) do
    head + sum_int_list(tail)
  end

  def calculate_string_list_sum(string_list) do
    string_list
    |> string_list_to_int_list
    |> sum_int_list
  end

  def list_sum_by_reducing(string_list) do
    string_list
    |> string_list_to_int_list
    |> reduce_int_list_by_sum
  end

  def sum_up_to_nth_element(string_list, n) do
    string_list
    |> Enum.slice(0, n + 1)
    |> Enum.map(&String.to_integer/1)
    |> Enum.reduce(fn x, acc -> acc + x end)
  end

  def construct_nth_sum_list(string_list) do
    (for {_number, counter} <- string_list
                               |> Enum.with_index, do: string_list
                                                       |> sum_up_to_nth_element(counter))
  end

  def sum_of_nth_sums_of_list(string_list) do
    string_list |> construct_nth_sum_list |> sum_int_list
  end

  def main(args) do
    IO.puts args |> sum_of_nth_sums_of_list
  end
end
