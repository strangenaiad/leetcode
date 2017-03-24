func twoSum(nums []int, target int) []int {
    var x int
    var y int
    var delta int
    for x=1; x<len(nums); x++ {
        delta = target - nums[x]
        
        for y=0; y<x; y++ {
            if delta==nums[y] {
                return []int { y, x}
            }
        }
    }
    
    return []int {0,0}
}