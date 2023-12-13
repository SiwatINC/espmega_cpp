#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <mqtt/async_client.h>

class ESPMegaMQTTCallback : public virtual mqtt::callback
{
public:
    void connection_lost(const std::string &cause) override;
    void delivery_complete(mqtt::delivery_token_ptr tok) override;
    void message_arrived(mqtt::const_message_ptr msg) override;
    void *message_arrive_pass_through;
};

class ESPMega
{
public:
    ESPMega(mqtt::async_client *client);
    ~ESPMega();
    void digital_write(uint8_t pin, bool value);
    void pwm_write(uint8_t pin, bool state, uint16_t value);
    uint16_t pwm_get_value(uint8_t pin);
    bool pwm_get_state(uint8_t pin);
    bool digital_read(uint8_t pin);
    void dac_write(uint16_t value);
    uint16_t adc_read(uint8_t pin);

private:
    mqtt::async_client *client;
    ESPMegaMQTTCallback *callback;
    mqtt::topic *base_topic;
    bool *input_states_buffer;
    bool *pwm_states_buffer;
    uint16_t *pwm_values_buffer;
    static constexpr num_pwms = 16;
    static constexpr num_inputs = 16;
};
