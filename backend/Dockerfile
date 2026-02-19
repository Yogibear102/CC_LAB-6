FROM gcc:latest
WORKDIR /app
COPY app.c .
RUN gcc app.c -o app
CMD ["./app"]