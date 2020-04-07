package com.shashi.interfaces;

public class AppTest {

    public static void main(String[] args) {

        // db_name = "mysql" - Spring Boot - DI
        // BalanceService balanceService = new BalanceServiceImplUsingDynamoDB();
        //
        BalanceService balanceServiceImplUsingDynamoDB = new BalanceServiceImplUsingDynamoDB();

        BalanceService balanceServiceImplUsingMySQL = new BalanceServiceImplUsingMySQL();

       BalanceManager balanceManager = new BalanceManager();

       balanceManager.setBalance(balanceServiceImplUsingDynamoDB, "1", 10);
       balanceManager.setBalance(balanceServiceImplUsingMySQL, "2" , 20);

        int bal = balanceManager.getBalance(balanceServiceImplUsingDynamoDB, "1");

        System.out.println(bal);
    }
}
