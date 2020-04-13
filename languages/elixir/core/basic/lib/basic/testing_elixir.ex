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


  def main(args) do
    IO.puts list_sum_by_reducing(args)
  end
end
