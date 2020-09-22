module.exports = {
  plugins: [
    "tailwindcss",
   process.env.NODE_ENV === "production"
      ? [
          "@fullhuman/postcss-purgecss",
          {
            content: [
              "./pages/**/*.{js,jsx,ts,tsx,re}",
              "./components/**/*.{js,jsx,ts,tsx,re}",
            ],
            defaultExtractor: require("@dylanirlbeck/tailwind-ppx").extractor,
          },
        ]
      : undefined,
    "autoprefixer",
  ]
};
