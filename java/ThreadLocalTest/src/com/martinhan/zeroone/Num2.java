package com.martinhan.zeroone;

import java.util.HashMap;

public class Num2 {
	private HashMap<Long,Integer> map = new HashMap<Long,Integer>();
	
	public Num2() {
		super();
	}

	public Num2(int value) {
		super();
		this.map.put(Thread.currentThread().getId(), value);
	}

	public Integer getValue() {
		return map.get(Thread.currentThread().getId());
	}

	public synchronized void setValue(int value) {
		this.map.put(Thread.currentThread().getId(), value);
	}
	
	public synchronized void addValue(int value) {
		if(map.containsKey(Thread.currentThread().getId()) == false) {
			return ;
		}
		int oldvalue = map.get(Thread.currentThread().getId());
		map.put(Thread.currentThread().getId(), oldvalue + value);
	}
}
