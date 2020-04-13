defmodule Basic.PlayingWithElixir do
  def hello, do: IO.puts "Hello Elixir World!"
  def hello(name) do
    IO.puts "Hello #{name}!"
  end

  def greet(name) do
    IO.puts "Hello #{name}!"
  end

  def sum_list([]), do: 0
  def sum_list([head|tail]) do
    head + sum_list(tail)
  end

  def calculate_string_list_sum(string_list) do
    # IO.puts sum_list(string_list |> Enum.map(&String.to_integer/1))
    string_list
    |> Enum.map(&String.to_integer/1)
    |> sum_list
  end

  def list_sum_by_reducing(string_list) do
    string_list
    |> Enum.map(&String.to_integer/1)
    |> Enum.reduce(fn x, acc -> acc + x end)
  end


  def main(args) do
    IO.puts list_sum_by_reducing(args)
  end
end
