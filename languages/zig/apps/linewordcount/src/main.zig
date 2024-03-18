const std = @import("std");

// The Plan:
// - the functionality in a separate source file
// - Takes one argument from command line
// - Reads the contents of the file into a vector of lines
// - Counts the amount of lines
// - Counts the amount of lines without empty lines
// - Counts the amount of words in the file

pub fn main() !void {
    // Prints to stderr (it's a shortcut based on `std.io.getStdErr()`)
    // std.debug.print("All your {s} are belong to us.\n", .{"codebase"});
    // const stdout_file = std.io.getStdOut().writer();
    // var bw = std.io.bufferedWriter(stdout_file);
    // const stdout = bw.writer();
    var alloc = std.heap.page_allocator;
    var args = try std.process.argsWithAllocator(alloc);
    defer args.deinit(); //std.process.argsFree(alloc, args);

    //while (args.next()) |arg| {
    // var argsarr = [10];
    // while (args.next()) |arg| {
    //     argsarr += arg.*;
    // }
    //}
}
