package com.martinhan.zeroone;

public class Num1 {
	private int value;
	
	public Num1() {
		super();
	}

	public Num1(int value) {
		super();
		this.value = value;
	}

	public int getValue() {
		return value;
	}

	public void setValue(int value) {
		this.value = value;
	}
	
	public void addValue(int value) {
		this.value += value;
	}
}
