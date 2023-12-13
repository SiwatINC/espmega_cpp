#include <espmega.hpp> 

// Path: src/espmega.cpp

void ESPMegaMQTTCallback::connection_lost(const std::string& cause) {

}
void ESPMegaMQTTCallback::delivery_complete(mqtt::delivery_token_ptr tok) {

}
void ESPMegaMQTTCallback::message_arrived(mqtt::const_message_ptr msg) {

}


ESPMega::ESPMega(mqtt::async_client* client) : client(client) {
    this->pwm_values_buffer = new uint16_t[num_pwms];
    this->pwm_states_buffer = new bool[num_pwms];
    this->input_states_buffer = new bool[num_inputs];
}
ESPMega::~ESPMega() {
    delete[] this->pwm_values_buffer;
    delete[] this->pwm_states_buffer;
    delete[] this->input_states_buffer;
}