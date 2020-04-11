defmodule Basic.TheServer do
  use GenServer
  import Basic.PlayingWithElixir
  def start_link(_args) do
    GenServer.start_link(__MODULE__, :ok)
  end

  def init(init_arg) do
    main()
    {:ok, init_arg}
  end
end
