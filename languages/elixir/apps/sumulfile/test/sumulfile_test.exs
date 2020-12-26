defmodule SumulfileTest do
  use ExUnit.Case
  doctest Sumulfile

  test "greets the world" do
    assert Sumulfile.hello() == :world
  end
end
