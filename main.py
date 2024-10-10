class Node:
    def __init__(self, data, next=None):
        self.data = data
        self.next = next

    
    
class LinkedList:
    def __init__(self):
        self.head = None
    def insert(self, data):
        newNode = Node(data)
        if self.head is None:
            self.head = newNode
            return
        last = self.head
        while last.next:
            last = last.next
        last.next = newNode
    def printList(self):
        curr = self.head
        while curr:
            print(curr.data)
            curr = curr.next

if __name__ == '__main__':
    llist = LinkedList()
    llist.insert(1)
    llist.insert(2)
    llist.insert(3)
    llist.printList()