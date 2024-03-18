int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    int sum = 0;
    int count = 0;

    while (tickets[k] > 0) {
        for (int i = 0; i < ticketsSize && tickets[k] > 0; i++) {
            if (tickets[i] > 0) {
                sum += 1;
                tickets[i]--;
                count++;
            }
        }
    }

    return sum;
}