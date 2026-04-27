const std = @import("std");

fn swap(a: *i64, b: *i64) void {
    if(a==b){return;}
    a.* = a.*^b.*;
    b.* = a.*^b.*;
    a.* = a.*^b.*;
}

fn rotate(arr: []i64) void {
    var i: usize =0; 
    var j: usize = arr.len - 1;
    while (i<j) {
        while (arr[j]==0 and i<j) {
            j -= 1;
        }
        while (arr[i]!=0 and i<j) {
            i += 1;
        }
        swap(&arr[i], &arr[j]);
    }
}

pub fn main() !void {
    var a = [_]i64{1,0,2,0,5,0,3,0,7,9,0,0};
    rotate(&a);
    for(a) |i| {
        std.debug.print("{} ", .{i});
    }
    std.debug.print("\n", .{});
}
