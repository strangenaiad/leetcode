
//   0                   1 ...
//   0 1 2 3 4 5 6 7 8 9 0 ...
//     |         |
//     Top       Bot

type Choice struct {
    Play1 int
    Play2 int
    Turn1 bool
    Top int
    Bot int
}


func PredictTheWinner(nums []int) bool {
    // 跟 connected component 一樣，透過 BFS 來解決

    maxiPlay1 := 0
    maxiPlay2 := 0

    queue := []Choice{{ 0, 0, true, 0, len(nums) }}
    for len(queue)>0 {
        node := queue[0]
        queue = queue[1:]
        fmt.Println( node )

        if node.Top < node.Bot {
            if node.Turn1 {
                queue = append( queue, Choice{ node.Play1+nums[node.Top], node.Play2, false, node.Top+1, node.Bot })
                queue = append( queue, Choice{ node.Play1+nums[node.Bot-1], node.Play2, false, node.Top, node.Bot-1 })
            } else {
                queue = append( queue, Choice{ node.Play1, node.Play2 + nums[node.Top], true, node.Top+1, node.Bot })
                queue = append( queue, Choice{ node.Play1, node.Play2 + nums[node.Bot-1], true, node.Top, node.Bot-1 })
            }
        } else {
            if maxiPlay1 < node.Play1 {
                maxiPlay1 = node.Play1
            }
            
            if maxiPlay2 < node.Play2 {
                maxiPlay2 = node.Play2
            }

            fmt.Printf( "%d %d\n", maxiPlay1, maxiPlay2 )
        }
    }
    
    if maxiPlay2 > maxiPlay1 {
        return false
    }
    
    return true
}



