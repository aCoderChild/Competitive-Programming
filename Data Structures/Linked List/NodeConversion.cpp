Node* convert(Node* head) {
    if (!head || !head->next) {
        return head;
    }
    
    // Step 1: Find the length of the linked list
    int n = 0;
    Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        n++;
    }
    
    // Calculate the midpoint
    int mid = n / 2;
    
    // Step 2: Split the list into two halves
    Node* firstHalf = head;
    Node* secondHalf = head;
    
    Node* prev = NULL;
    for (int i = 0; i < mid; i++) {
        prev = secondHalf;
        secondHalf = secondHalf->next;
    }
    // Break the list into two halves
    if (prev) {
        prev->next = NULL;
    }
    
    // Step 3: Interleave the two halves
    Node* firstHalfNext;
    Node* secondHalfNext;
    Node* current = new Node();
    Node* dummy = current; // Dummy node to facilitate the interleaving process

    while (firstHalf && secondHalf) {
        firstHalfNext = firstHalf->next;
        secondHalfNext = secondHalf->next;
        
        current->next = firstHalf;
        firstHalf->next = secondHalf;
        current = secondHalf;
        
        firstHalf = firstHalfNext;
        secondHalf = secondHalfNext;
    }

    // If there are any remaining nodes in the first half, attach them at the end
    if (firstHalf) {
        current->next = firstHalf;
    } else if (secondHalf) { // Unlikely in this specific problem, but just in case
        current->next = secondHalf;
    }

    return dummy->next;
}
