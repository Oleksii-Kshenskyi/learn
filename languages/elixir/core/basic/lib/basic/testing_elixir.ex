defmodule Basic.PlayingWithElixir do
  def hello, do: IO.puts "Hello Elixir World!"
  def hello(name) do
    IO.puts "Hello #{name}!"
  end

  def greet(name) do
    IO.puts "Hello #{name}!"
  end


  def main(args) do
    greet(args)
    :ok
  end
end
