class SegTree:
    def __init__(self, l):
        self.n = len(l)
        self.tree = []
        
        # Pad l
        while bin(self.n).count("1") != 1:
            l.append(0)
            self.n += 1 
            
        # Create tree
        for _ in range(2*self.n):
            self.tree.append(0)

        for i in range(self.n):
            self.tree[self.n + i] = l[i]
            
        for i in range(self.n - 1, 0, -1):
            self.tree[i] = self.tree[i*2] + self.tree[i*2 + 1]     
            
    def query(self, node, node_low, node_high, query_low, query_high):
        if node_low >= query_low and node_high <= query_high:
            return self.tree[node]
        
        if node_high < query_low or node_low > query_high:
            return 0
        
        mid = (node_low + node_high) // 2 # Last in the left
        
        return self.query(node*2, node_low, mid, query_low, query_high) \
                + self.query(node*2 + 1, mid+1, node_high, query_low, query_high)
        
    def update(self, index, new_val):
        node = self.n + index
        self.tree[node] = new_val
        
        node //= 2 # Backtrack iteratively
        while node > 0:
            self.tree[node] = self.tree[node*2] + self.tree[node*2 + 1]   
            node //= 2 
             