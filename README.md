# Auto Top Off fro Aquariums

Auto Top Off (ATO) device to replenish freshwater in saltwater aquariums. 
It is built with custom ESPHome firmware and only parts that can be sourced online, in web-sites like eBay and Aliexpress.
This is a nice weekend project for the average tinkerer and is purposely designed to be easy to build, without special tools nor programming knowledge.


**Status**: beta testing

                           
# Useful commands
             
 ## Build & upload firmware
    `docker run --rm -v "${PWD}":/config -it esphome/esphome run open-ato-esp.yaml --device open-ato-esp.local`

 ## ESPHome Dashboard
    ```
    docker run --rm -p 6052:6052 -v "${PWD}":/config -it esphome/esphome dashboard config/
    open http://localhost:6052/
    ```

# Features
 * ATO with single float or dual float switch sensor and 12V freshwater pump (actuator/switch).
 * Customisable pump timeout.
 * Based on ESPHome firmware and consequently compatible with Home Assistant, MQTT, etc.
 * Over the air (OTA) updates
 * Mini OLED Display
 * Programming can be fully modified using a yaml file (no need for advanced programming skills)


# Parts list
 * NodeMCU v1.
 * NodeMCU shield with 12V input.
 * 2x float switches
 * Mosfet switch
 * Pump
 * mini Oled 0.96" display
 * Wires and connectors.
 
Tested with NodeMCU v1.0 boards.
                        
Proudly sponsored by inventmarine.com

Developed by Franklin Dattein 


# Backlog
* Make sure pump turns on when booting
* Sort out git commit
* Evaluate the feasibility of writting tests
* CI Build?
* Instructions
  ** Fritizing Diagram
* 3D Printable enclosure
 