type Pos struct {
    Row int
    Col int
    Dist  int
}


func updateMatrix(matrix [][]int) [][]int {
    que := make([]Pos, 0)
    
    result := make( [][]int, len(matrix))
    for y:=0; y<len(matrix); y++ {
        result[y] = make( []int, len(matrix[y]))
        for x:=0; x<len(matrix[y]); x++ {

            if matrix[y][x]==0 {
                result[y][x] = 0
                que = append( que, Pos{ y, x, 0})
            } else {
                result[y][x] = -1
            }
        }
    }
    
    for len(que)>0 {
        Row, Col, Dist := que[0].Row, que[0].Col, que[0].Dist
        que = que[1:] // move to next

        if result[Row][Col]>=0 && Dist>result[Row][Col] {
            continue
        }

        if result[Row][Col]>Dist || result[Row][Col]<0 {
            result[Row][Col] = Dist
        }

        // UP
        if Row>0 {
            que = append( que, Pos{ Row-1, Col, Dist+1 })
        }
        
        // RIGHT
        if Col+1<len(result[0]) {
            que = append( que, Pos{ Row, Col+1, Dist+1 })
        }
        
        // DOWN
        if Row+1<len(result) {
            que = append( que, Pos{ Row+1, Col, Dist+1 })
        }
        
        // LEFT
        if Col>0 {
            que = append( que, Pos{ Row, Col-1, Dist+1 })
        }
    }
    
    return result
}
