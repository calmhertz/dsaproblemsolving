const std = @import("std");

pub fn main(init: std.process.Init) !void {
    _ = init;

    const TestCase = struct {
        nums: []const i32,
        expected: i32,
        description: []const u8,
    };

    const cases = [_]TestCase{
        .{ .nums = &[_]i32{3, 4, 5, 1, 2}, .expected = 1, .description = "Pivot in middle" },
        .{ .nums = &[_]i32{4, 5, 6, 7, 0, 1, 2}, .expected = 0, .description = "Pivot right of center" },
        .{ .nums = &[_]i32{11, 13, 15, 17}, .expected = 11, .description = "Fully sorted (n rotations)" },
        .{ .nums = &[_]i32{2, 1}, .expected = 1, .description = "Smallest n=2 rotated" },
        .{ .nums = &[_]i32{1, 2}, .expected = 1, .description = "Smallest n=2 sorted" },
        .{ .nums = &[_]i32{10}, .expected = 10, .description = "Single element" },
        .{ .nums = &[_]i32{2, 3, 4, 5, 6, 7, 8, 1}, .expected = 1, .description = "Pivot at the end" },
        .{ .nums = &[_]i32{8, 1, 2, 3, 4, 5, 6, 7}, .expected = 1, .description = "Pivot at the start" },
        .{ .nums = &[_]i32{5, -1, 0, 1, 2, 3, 4}, .expected = -1, .description = "Negative values with pivot" },
        .{ .nums = &[_]i32{-5, -4, -3, -2, -1}, .expected = -5, .description = "All negative sorted" },
    };

    var solution = Solution{};

    for (cases) |case| {
        const actual = solution.findMin(case.nums);
        if (actual != case.expected) {
            std.debug.print("FAIL: {s}\nInput: {any}\nExpected: {d}, Got: {d}\n\n", .{ 
                case.description, 
                case.nums, 
                case.expected, 
                actual 
            });
            std.process.exit(1);
        }
    }

    std.debug.print("All test cases passed.\n", .{});
}

const Solution = struct {
    pub fn findMin(self: *Solution, nums: []const i32) i32 {
        _ = self;
        if(nums.len == 1){
            return nums[0];
        }
        else if(nums[0]<nums[nums.len-1]){
            return nums[0];
        }
        for(0..nums.len-1) |i| {
            if(nums[i]>nums[i+1]){
                return nums[i+1];
            }
        }
        return 0;
    }
};
