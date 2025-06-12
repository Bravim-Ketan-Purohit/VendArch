#include "State.h"
#include <iostream>
using namespace std;

State::State(MDA_EFSM *m) { efsm = m; }

void State::create() { cout << "[ERROR] create() not allowed in current state.\n"; }
void State::insert_cups(int) { cout << "[ERROR] insert_cups() not allowed in current state.\n"; }
void State::coin(float) { cout << "[ERROR] coin() not allowed in current state.\n"; }
void State::card(float) { cout << "[ERROR] card() not allowed in current state.\n"; }
void State::set_price(float) { cout << "[ERROR] set_price() not allowed in current state.\n"; }
void State::cancel() { cout << "[ERROR] cancel() not allowed in current state.\n"; }
void State::cappuccino() { cout << "[ERROR] cappuccino() not allowed in current state.\n"; }
void State::chocolate() { cout << "[ERROR] chocolate() not allowed in current state.\n"; }
void State::sugar() { cout << "[ERROR] sugar() not allowed in current state.\n"; }

State::~State() {}
