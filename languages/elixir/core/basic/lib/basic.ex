defmodule Basic.Hello do
  use GenServer

  def hello do
    IO.puts "Hello Elixir World!"
  end

  def start_link(_args) do
    GenServer.start_link(__MODULE__, :ok)
  end

  def init(init_arg) do
    hello()
    {:ok, init_arg}
  end
end
