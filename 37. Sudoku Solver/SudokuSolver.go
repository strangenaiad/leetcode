
type CELL struct {
    Y int
    X int
    Possibles []byte
}


func removePossible( cell *CELL, ch byte ) {
    found:=false
    z:=0
    for z<len((*cell).Possibles) {
        if (*cell).Possibles[z]==ch {
            found = true
            break
        }
        z++
    }
    
    if !found {
        return
    }

    //fmt.Printf( "removed %d, %d %c", cell.Y, cell.X, ch )

    for z+1<len((*cell).Possibles) {
        (*cell).Possibles[z] = (*cell).Possibles[z+1]
        z++
    }
    
    (*cell).Possibles = (*cell).Possibles[:len((*cell).Possibles)-1]
    fmt.Println( *cell )
    
}


func display( board [][]byte ) {
    for y:=range(board) {
        if y==3 || y==6 {
            fmt.Printf("\n")
        }
        
        for x:=range(board[y]) {
            if x==3 || x==6 {
                fmt.Printf( "  ")
            }
            fmt.Printf( "%c", board[y][x] )
        }
        
        fmt.Printf("\n")
    }
    
    fmt.Printf( "-------------\n" )
    
}


func solveSudoku(board [][]byte)  {
    unsolved := make( []CELL, 0, 9*9*9 )

    y:=0
    x:=0
    z:=0
    for y=range(board) {
        for x=range(board) {
            if board[y][x]=='.' {
                unsolved = append( unsolved, CELL{ y, x, []byte{'1','2','3','4','5','6','7','8','9' }})
            }
        }
    }
    
    count:=0

    for len(unsolved)>0 {
        cell := unsolved[0]
        unsolved = unsolved[1:]
        
        for i:=range(board) {
            // check vertical 
            if board[i][cell.X]!='.' {
                //fmt.Println( "vertical: ", i, cell.X, board[i][cell.X] )
                removePossible( &cell, board[i][cell.X] )
            }
            
            // check horizontal
            if board[cell.Y][i]!='.' {
                //fmt.Println( "horizontal: ", cell.Y, i, board[cell.Y][i] )
                removePossible( &cell, board[cell.Y][i] )
            }
        }

        // check chunk
        chunk_y0 := 3*(cell.Y/3)
        chunk_x0 := 3*(cell.X/3)
        
        for a:=0; a<3; a++ {
            chunk_y := chunk_y0 +a
            
            for b:=0; b<3; b++ {
                chunk_x := chunk_x0 +b
                
                if board[chunk_y][chunk_x]!='.' {
                    //fmt.Println( "chunk: ", chunk_y, chunk_x, board[chunk_y][chunk_x] )
                    removePossible( &cell, board[chunk_y][chunk_x] )
                }
            }
        }

        // only 1 possible
        if len(cell.Possibles)==1 {
            board[cell.Y][cell.X] = cell.Possibles[0]
            count = 0
            display(board)
            continue
        }
        
        
        for z=range(cell.Possibles) {
            
            // 1 only possible in vertical/horizontal/chunk
            unique := true
            for other:=range(unsolved) {
                if unsolved[other].X==cell.X || unsolved[other].Y==cell.Y || (unsolved[other].X/3==cell.X/3 && unsolved[other].Y/3==cell.Y/3) {
                    
                    for z2:=range(unsolved[other].Possibles) {
                        if cell.Possibles[z] == unsolved[other].Possibles[z2] {
                            unique = false
                            break
                        }
                    }
                    
                    if !unique {
                        break
                    }
                }
            }
            
            if unique {
                fmt.Printf( "unique %d %d %c\n", cell.Y, cell.X, cell.Possibles[z] )
                cell.Possibles = []byte{cell.Possibles[z]}
                break
                //fmt.Println(cell)
            }
        }
        

        // put it back            
        fmt.Println(cell)
        unsolved = append( unsolved, cell )

        count++
        if count>len(unsolved) {
            break
        }
    }
}
