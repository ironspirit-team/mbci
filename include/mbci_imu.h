/**
 * @file mbci_imu.h
 * @author Evan Xiao (1993996310@qq.com)
 * @brief IMU设备的抽象。
 * @version 0.1
 * @date 2023-10-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __MBCI_IMU_H__
#define __MBCI_IMU_H__

struct mbci_imu {
    /**
     * @brief 初始化 IMU 设备。
     * 
     */
    void (*init)(void);
    /**
     * @brief 读取加速度计的数据。
     * 
     * @param x 加速度计 X 轴的数据
     * @param y 加速度计 Y 轴的数据
     * @param z 加速度计 Z 轴的数据
     */
    void (*read_accel)(float *x, float *y, float *z);

    /**
     * @brief 读取陀螺仪的数据。
     * 
     * @param x 陀螺仪 X 轴的数据
     * @param y 陀螺仪 Y 轴的数据
     * @param z 陀螺仪 Z 轴的数据
     */
    void (*read_gyro)(float *x, float *y, float *z);

    /**
     * @brief 读取磁力计的数据。仅在设备支持时可用。如果不支持此功能，请将此函数指针设置为 NULL。
     * 
     * @param x 磁力计 X 轴的数据
     * @param y 磁力计 Y 轴的数据
     * @param z 磁力计 Z 轴的数据
     */
    void (*read_mag)(float *x, float *y, float *z);

    /**
     * @brief 读取欧拉角的数据。仅在设备支持时可用。如果不支持此功能，请将此函数指针设置为 NULL。
     * @param pitch 欧拉角的俯仰角, 单位为度，范围为 -180~180
     * @param roll 欧拉角的横滚角, 单位为度，范围为 -180~180
     * @param yaw 欧拉角的偏航角, 单位为度，范围为 -180~180
     * 
     */
    void (*read_euler)(float *pitch, float *roll, float *yaw);

        /**
     * @brief 私有数据，供驱动开发者使用。
     * 
     */
    void *priv;
};

#define mbci_imu_init(imu) ((imu)->init())
#define mbci_imu_read_accel(imu, x, y, z) ((imu)->read_accel(x, y, z))
#define mbci_imu_read_gyro(imu, x, y, z) ((imu)->read_gyro(x, y, z))
#define mbci_imu_read_mag(imu, x, y, z) ((imu)->read_mag(x, y, z))
#define mbci_imu_read_euler(imu, pitch, roll, yaw) ((imu)->read_euler(pitch, roll, yaw))

#define mbci_imu_is_supported_mag(imu) ((imu)->read_mag != NULL)
#define mbci_imu_is_supported_euler(imu) ((imu)->read_euler != NULL)


#endif // __MBCI_IMU_H__

