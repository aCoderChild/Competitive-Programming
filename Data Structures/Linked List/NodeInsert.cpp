bool isIncrease (Node* head) {
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    
    if (tail->value - head->value > 0) return true;
    return false;
}

Node* insert(Node* head, int value) {
    Node* toInsert = new Node();
    toInsert->value = value;
    toInsert->next = NULL;
    
    if (head == NULL) return toInsert;
    
    if (head->next == NULL) {
        if (head->value > value) {
            toInsert->next = head;
            return toInsert;
        }
        
        head->next = toInsert;
        return head;
    }
    
    if ((isIncrease(head) && value < head->value) || (!isIncrease(head) && value > head->value)) {
        toInsert->next = head;
        return toInsert;
    }
    
    Node* current = head;
    while (current->next != NULL) {
        if ((current->next->value > value && isIncrease(head)) || (current->next->value < value && !isIncrease(head))) {
            Node* next = current->next;
            current->next = toInsert;
            toInsert->next = next;
            break;
        }
        current = current->next;
    }
    
    current->next = toInsert;
    return head;
}