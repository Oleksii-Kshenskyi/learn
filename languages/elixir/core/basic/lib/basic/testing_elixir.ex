defmodule Basic.PlayingWithElixir do
  def hello, do: IO.puts "Hello Elixir World!"
  def hello(name) do
    IO.puts "Hello #{name}!"
  end


  def main do
    hello("Someone")
  end
end
