pragma solidity ^0.8.22;

contract Account{
    address public account;
    uint128 public balance;

    constructor(){
        account = msg.sender;
    }

    function deposit(uint128 amount)public{
        balance += amount;
    }

    function withdraw(uint128 amount)public{
        require(balance > amount, "Insufficient balance");
        balance -= amount;
    }

    function viewbalance() public view returns(uint128){
        return balance;
    } 
}
