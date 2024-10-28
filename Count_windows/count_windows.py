import cv2
import numpy as np
import os


def count_windows(image_path):

    # 读取图片
    image = cv2.imread(image_path)
    if image is None:
        print(f"无法读取图片: {image_path}. 请检查文件是否损坏或格式是否支持。")
        return 0

    # 转换为灰度图，因为灰度图在处理轮廓时更为高效
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    # 应用高斯模糊，减少噪声
    blurred = cv2.GaussianBlur(gray, (5, 5), 0)
    # 应用中值模糊，进一步减少噪声
    filtered = cv2.medianBlur(gray, 5)

    # 应用阈值分割，将图像转换为二值图像（黑白），方便后续轮廓检测
    _, thresh = cv2.threshold(filtered, 24, 255, cv2.THRESH_BINARY_INV)

    # 查找轮廓
    contours, _ = cv2.findContours(thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    # 初始化窗户计数和最大轮廓变量
    window_count = 0
    largest_area = 0
    largest_contour = None

    # 遍历所有轮廓，找到面积最大的轮廓（可能是建筑物或墙壁等）
    for contour in contours:
        area = cv2.contourArea(contour)
        if area > largest_area:
            largest_area = area
            largest_contour = contour

            # 再次遍历所有轮廓，统计除最大轮廓外的其他轮廓（假设它们是窗户），
    # 并且这些轮廓的面积在指定的范围内（这里假设窗户的面积在500到30000之间）
    for contour in contours:
        area = cv2.contourArea(contour)
        if contour is not largest_contour and 30000 > area > 500:
            window_count += 1
            # 在原图上绘制找到的轮廓（绿色边框）
            cv2.drawContours(image, [contour], -1, (0, 255, 0), 2)

            # 将处理后的图片保存到'result'文件夹中
    result_path = os.path.join('result', os.path.basename(image_path))
    cv2.imwrite(result_path, image)

    return window_count


def main():
    # 如果'result'文件夹不存在，则创建它
    if not os.path.exists('result'):
        os.makedirs('result')

        # 指定图片文件夹路径
    image_folder = './image'
    # 获取该文件夹下所有符合图片格式（jpg, jpeg, png）的文件名
    image_filenames = [f for f in os.listdir(image_folder) if f.endswith(('.jpg', '.jpeg', '.png'))]

    # 如果没有找到任何图片，则打印提示信息并返回
    if not image_filenames:
        print("指定的文件夹中没有找到任何图片。")
        return

        # 遍历所有图片文件，统计每张图片中的窗户数量
    for filename in image_filenames:
        image_path = os.path.join(image_folder, filename)
        window_count = count_windows(image_path)
        print(f"图片 {filename} 中，窗户数量为 {window_count} 个。")


if __name__ == "__main__":
    main()