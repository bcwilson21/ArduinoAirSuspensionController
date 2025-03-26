set(srcs

        "airSuspensionUtil.cpp"
        "input_type.cpp"
        "manifoldSaveData.cpp"
        "pressureMath.cpp"
        "bluetooth/ble.cpp"
        "components/compressor.cpp"
        "components/manifold.cpp"
        "components/pressure_sensor.cpp"
        "components/screen.cpp"
        "components/solenoid.cpp"
        "components/wheel.cpp"
        "ota/ota.cpp"
        "tasks/tasks.cpp")

set(requires "bluepad32" "bluepad32_arduino" "arduino" "btstack")

idf_component_register(SRCS "${srcs}"
                    INCLUDE_DIRS "."
                    REQUIRES "${requires}")
