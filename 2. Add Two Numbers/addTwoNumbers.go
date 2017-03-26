/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    
    left := l1
    right := l2
    carry := 0
    result := ListNode{ -1, nil }

    // 如果還有節點或是進位未處理
    for left!=nil || right!=nil || carry!=0 {
        Val := 0

        // 左節點的值
        if left!=nil {
            Val += (*left).Val
            left = (*left).Next
        }
        
        // 右節點
        if right!=nil {
            Val += (*right).Val
            right = (*right).Next
        }
        
        // 把上次的進位放進來
        if carry>0 {
            Val += carry
            carry = 0
        }
        
        // 把這次的進位存起來
        if Val>=10 {
            carry = 1
            Val -= 10
        }

        // 結果寫入鍊結
        if result.Val==-1 {
            result.Val = Val
            
        } else {
            tail := &result
            for (*tail).Next!=nil {
                tail = tail.Next
            }
            
            another := ListNode{ Val, nil }
            (*tail).Next = &another
        }

        //fmt.Println( result )
    }
    
    
    
    return &result
}