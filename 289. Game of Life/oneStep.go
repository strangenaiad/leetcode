

func nextStep( board [][]int ) {
    hi := len(board)
    wi := len(board[0])
    temp := make( []int, wi*hi )
    
    for y:=0; y<hi; y++ {
        for x:=0; x<wi; x++ {
            neighbors := 0
            survive := 0
            
            if y>0 {
                if x>0 {
                    neighbors += board[y-1][x-1]
                }
                
                neighbors += board[y-1][x]
                
                if x+1<wi {
                    neighbors += board[y-1][x+1]
                }
            }
            
            if x>0 {
                neighbors += board[y][x-1]
            }
            
            if x+1<wi {
                neighbors += board[y][x+1]
            }

            if y+1<hi {
                if x>0 {
                    neighbors += board[y+1][x-1]
                }
                
                neighbors += board[y+1][x]
                
                if x+1<wi {
                    neighbors += board[y+1][x+1]
                }
            }
            
            
            if neighbors<2 {
                // Any live cell with fewer than two live neighbors dies, as if caused by under-population.
            } else if neighbors>3 {
                // Any live cell with more than three live neighbors dies, as if by over-population..
            } else if neighbors==3 {
                // Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
                survive = 1
            } else if neighbors==2 {
                //Any live cell with two or three live neighbors lives on to the next generation.
                survive = board[y][x]
            }
    

            temp[y*wi+x] = survive
        }
    }
    
    // write back
    for y:=0; y<hi; y++ {
        for x:=0; x<wi; x++ {
            board[y][x] = temp[y*wi+x]
        }
    }
}


func gameOfLife(board [][]int)  {
    nextStep( board )
}