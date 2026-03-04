# 🎵 Song Playlist Management System

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Visual Studio](https://img.shields.io/badge/Visual_Studio-5C2D91?style=for-the-badge&logo=visual%20studio&logoColor=white)
![Data Structures](https://img.shields.io/badge/Data_Structures-Linked_List-green?style=for-the-badge)

A comprehensive console-based music playlist manager developed as part of the Data Structures course. This project demonstrates the practical implementation of doubly linked lists for dynamic data management with file persistence.

## 📋 Features

### Core Functionalities
- **Add Songs** - Insert new songs with artist names
- **Delete Songs** - Remove songs with automatic file update
- **Search Songs** - Find and auto-play searched songs
- **Shuffle Play** - Random playback mode
- **Display Playlist** - View all songs in order
- **File Persistence** - Automatic save/load from `playlist.txt`

### Technical Features
- ✅ Doubly linked list implementation
- ✅ Bidirectional traversal
- ✅ Dynamic memory management
- ✅ File I/O operations
- ✅ .WAV audio file support
- ✅ Error handling for file operations

## 🎯 Implemented Operations

| Operation | Description | Time Complexity |
|-----------|-------------|-----------------|
| Add Song | Insert at end | O(n) |
| Delete Song | Remove by name | O(n) |
| Search Song | Find and play | O(n) |
| Display | Show all songs | O(n) |
| Shuffle | Random order play | O(n) |

## 🛠️ Technology Stack

- **Language:** C++
- **IDE:** Visual Studio 2022
- **Data Structure:** Doubly Linked List
- **Storage:** File System (playlist.txt)
- **Audio Format:** .WAV files

## 🚀 Getting Started

### Prerequisites
- Visual Studio 2019 or 2022
- Windows OS (for .WAV playback)
- C++ compiler

### Installation & Running

1. **Clone the repository**
```bash
git clone https://github.com/Adventurw/song-playlist-linkedlist.git
