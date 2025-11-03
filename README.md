# 🛣️ Classical Lane Detection (OpenCV + C++)  

This project demonstrates a **traditional lane detection pipeline** using edge detection and Hough transform — the kind of early computer vision approach often used in the first generation of ADAS systems.  

> ⚠️ **Note:**  
> This classical method is highly sensitive to lighting, shadows, camera angle, and road conditions.  
> It serves as a learning exercise, but it’s **not reliable for real-world autonomous driving.**  
> Modern lane detection relies on **deep learning (CNN-based)** or **sensor fusion** for robust performance.

---

### 🧠 What It Does
- Detects lane lines from dashcam footage  
- Uses grayscale conversion, Gaussian blur, Canny edge detection, and Hough transform  
- Highlights detected lane lines in green  

---

### ⚙️ Technologies
- **C++17**
- **OpenCV 4.x**
- **CMake**

---

### 🧩 Project Structure
