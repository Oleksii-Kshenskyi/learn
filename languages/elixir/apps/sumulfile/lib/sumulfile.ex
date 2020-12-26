defmodule Sumulfile do
  def main([filename]) do
    filename
    |> File.stream!
    |> Enum.to_list
    |> Enum.map(&String.trim/1)
    |> Enum.map(&String.to_integer/1)
    |> Enum.map(fn(e) -> e * 2 end)
    |> Enum.sum
    |> IO.inspect
  end
end
