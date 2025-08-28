# 🏦 Bank Management System

Welcome to the Bank Management System! 🎉

This is a comprehensive system developed in C++ using Object-Oriented Programming (OOP) principles. It offers a professional, educational, and flexible experience for managing clients, financial transactions, users, and permissions. 💼

Whether you're a student eager to grasp OOP concepts, a developer aiming to build real-world systems, or even managing a small bank or a simple financial activity, this system is designed to be your ideal choice. 💡

## 🌟 Why is this System Special?

### 🧠 Professional Software Design using OOP

*   **Encapsulation:** 🛡️ Protects data from arbitrary manipulation, ensuring data integrity.
*   **Inheritance:** ♻️ Reduces redundancy and promotes efficient code reuse, saving development time.
*   **Polymorphism:** ✨ Provides high flexibility in customizing and extending classes, making the system adaptable.
*   **Single Responsibility Principle:** 🎯 Each class is dedicated to a specific function, leading to cleaner and more maintainable code.

### ✨ Unique Features

*   **Powerful Learning Experience:** 📚 Perfect for hands-on learning of OOP concepts through a practical, real-world application.
*   **Advanced Security:** 🔒 Precise permissions for each operation ensure complete protection and prevent unauthorized access.
*   **Simple & Efficient Storage:** 💾 All data is stored in text files, making it portable and easy to maintain.
*   **User-Friendly Interactive Interface:** 🖥️ Clear menus and smart guidance for every step, ensuring a smooth user experience.
*   **Scalability:** 📈 Easily add new features or integrate the system with graphical interfaces in the future, allowing for growth.

## 🚀 Detailed Features

### 👥 Client Management

*   **Add New Clients:** ➕ Easily add new clients with all essential details.
*   **Update Client Data:** 🖋️ Quickly and efficiently update client information.
*   **Search for Clients:** 🔍 Find clients using their account number or name.
*   **Delete Clients:** ❌ Securely delete clients while retaining records for archiving purposes.
*   **View Client List:** 📋 Display an organized and easy-to-read list of all clients.

**Fields Stored for Each Client:**

| Field          | Description                               |
| :------------- | :---------------------------------------- |
| Account Number | A unique number for each client.          |
| PIN            | For verification during transactions.     |
| Name           | Full name of the client.                  |
| Phone          | Phone number.                             |
| Balance        | Current amount in the account.            |
| Status         | Active or Deleted.                        |

### 💰 Banking Transactions

*   **Deposit:** 💸 Easily add funds to an account.
*   **Withdraw:** 💵 Deduct funds with balance verification.
*   **Transfer:** 🔄 Securely and quickly transfer funds between accounts.
*   **View Total Balances:** 📊 See the total amount of money across all accounts.

**Tip:** All operations are protected by the permissions system to prevent errors or manipulation. 🔒

### 👨‍💻 User Management

*   **Add New Users:** 👤 Add new users, whether employees or managers.
*   **Define Precise Permissions for Each User:** 🔑
    *   Client management only.
    *   Transaction execution only.
    *   Full administrative permissions.
*   **Update User Data:** 🖋️ Update user information at any time.
*   **View Full User List:** 👀 Display a complete list of users and their permissions.

### 📈 Currency Exchange

*   **View Stored Currency Rates:** 🪙 Display currency rates stored in a dedicated file.
*   **Search for Specific Currency:** 🔍 Find a specific currency and its value.
*   **Update Exchange Rates:** ✏️ Easily update exchange rates.
*   **Accurate Conversion Calculations:** 🧮 Perform precise conversions between different currencies.

### 📝 Storage & Logging

*   **Simple & Organized Text Files:** 📂
    *   `Client.txt` – Client data.
    *   `Users.txt` – User data.
    *   `Currencies.txt` – Currency rates.
    *   `TransferLog.txt` – Transfer log.
    *   `RegisterLoginsUsers.txt` – Login/logout log.
*   **Automatic File Creation:** 🛡️ Files are automatically created upon first run if they don't exist.

## 🛠 System Requirements

*   **Modern C++ Compiler:** GCC, MSVC, or Clang. 💻
*   **Operating System:** Windows or Linux. 🐧
*   **Development Environment:** Visual Studio, Code::Blocks, or VS Code. 🚀
*   **No External Libraries:** Relies only on standard libraries, keeping it lightweight. 📦

## 📂 Full Project Structure

### 🧩 Client & Transaction Files

| File                      | Description                                   |
| :------------------------ | :-------------------------------------------- |
| `clsBankClient.h`         | Manages basic client data.                    |
| `clsAddNewClient.h`       | Adds new clients.                             |
| `clsDeleteClient.h`       | Securely deletes clients.                     |
| `clsUpdateClient.h`       | Updates client data.                          |
| `clsFindClient.h`         | Searches for clients.                         |
| `clsShowClientsList.h`    | Displays an organized list of clients.        |
| `clsTransferBalance.h`    | Transfers funds between accounts.             |
| `clsShowTotalBalance.h`   | Displays total balances.                      |
| `clsDepositeOperation.h`  | Handles deposit operations.                   |
| `clsWithdrawOperation.h`  | Handles withdrawal operations.                |

### 🧑‍💻 User Management & Permissions Files

| File                          | Description                                   |
| :---------------------------- | :-------------------------------------------- |
| `clsUserBank.h`               | Manages user data and permissions.            |
| `clsAddNewUser.h`             | Adds new users.                               |
| `clsDeleteUser.h`             | Deletes users.                                |
| `clsUpdateUser.h`             | Updates user data.                            |
| `clsFindUser.h`               | Searches for users.                           |
| `clsShowUserList.h`           | Displays all users with their permissions.    |
| `clsRegisterLogUsers.h`       | Logs login and logout operations.             |
| `clsMangeUserSecren.h/.cpp` | User management interface.                    |

### 💱 Currency Exchange Files

| File                        | Description                                   |
| :-------------------------- | :-------------------------------------------- |
| `clsCurrency.h`             | Manages currency data.                        |
| `clsFindCurrency.h`         | Searches for a specific currency.             |
| `clsShowListCurrency.h`     | Displays all currencies.                      |
| `clsUpdateRate.h`           | Updates currency rates.                       |
| `clsCalculatorCurrency.h`   | Performs currency conversion calculations.    |
| `clsMainMenuCurrencyExchange.h` | Currency exchange interface.                  |

### 🔧 Service & Helper Files

| File                          | Description                                   |
| :---------------------------- | :-------------------------------------------- |
| `clsLogin.h`                  | Manages login and verification.               |
| `clsMainMenuSecreen.h`        | Main menu interface.                          |
| `clsDate.h`                   | Handles dates and times.                      |
| `clsPerson.h`                 | Base class for personal information.          |
| `clsString.h`                 | String manipulation functions.                |
| `clsInputValidate.h`          | Input validation.                             |
| `clsUtility.h`                | General utility tools.                        |
| `GlobalVarablesAndConstants.h` | Stores global variables and constants.        |

## ⚡ How to Run

1.  **Copy all files** into a single folder. 📁
2.  **Open `main.cpp`** in your preferred development environment. 🚀
3.  **Build the project.** 🛠️
4.  **Run the program** and enjoy a smooth and interactive experience! ✨

## 💡 Important Tips

*   **Do not manually modify text files** unless you understand the required format. ⚠️
*   **Ensure the program runs with appropriate permissions** to save files. 🔑
*   **Try different user roles** to fully understand the permissions system. 👥

## 📛 Why the Name "BankPro"?

The project was named "BankPro" 🏦 to reflect its purpose as a professional and reliable banking system.
The word "Bank" 💰 represents the core functionality of the system — managing clients, accounts, and transactions.
The suffix "Pro" 🧑‍💻 stands for "Professional", indicating that the system is well-structured, scalable, and built with Object-Oriented Programming (OOP) principles ⚙️, making it suitable for advanced and professional-level use 🚀.

## 🤝 Contributing

Love this project? Want to improve it?  
Feel free to submit **Issues** or **Pull Requests** on GitHub — your contributions are highly appreciated! 🙌

---

# 👨💻 Author

**Ahmed Jehad Ahmed**  


🔗 [GitHub Profile](https://github.com/7mee3d)

📧 [Email Contact](mailto:enginnerahemdjehad2004@gmail.com)
