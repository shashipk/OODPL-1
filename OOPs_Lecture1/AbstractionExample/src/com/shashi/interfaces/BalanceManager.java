package com.shashi.interfaces;

public class BalanceManager {

    public int getBalance(BalanceService balanceService, String userId) {
       return balanceService.getBalance(userId);
    }

    public boolean setBalance(BalanceService balanceService, String userId, int balance){
        return balanceService.setBalance(userId,balance);
    }
}
