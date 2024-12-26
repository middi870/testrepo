from pytube import YouTube

def download_video(video_url):
    try:
        # Create YouTube object
        yt = YouTube(video_url)

        # Get the highest resolution stream
        video_stream = yt.streams.get_highest_resolution()

        print(f"Downloading: {yt.title}")
        
        # Download the video
        video_stream.download()
        print("Download complete!")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    url = input("Enter the YouTube video URL: ")
    download_video(url)
