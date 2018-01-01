/* TODO: Write this in ReasonML you lazy */
const { resolve } = require("path");
const { readFileSync, writeFileSync } = require("fs");
const got = require("got");
const cheerio = require("cheerio");
const _ = require("lodash");

(async () => {
  try {
    const response = await got("https://ant.design/components/icon/");
    const $ = cheerio.load(response.body);

    const icons = [];
    $(".anticon-class > .ant-badge").each(function(i, elem) {
      icons.push($(this).text());
    });
    let reFile = _.template(
      readFileSync(resolve(__dirname, "./Antd_IconName.re.template")).toString()
    );
    let reiFile = _.template(
      readFileSync(
        resolve(__dirname, "./Antd_IconName.rei.template")
      ).toString()
    );

    const resultIcons = icons.map(icon => {
      const varName = _.camelCase(icon);
      return [icon, varName === "exception" ? "exception_" : varName];
    });
    writeFileSync(
      resolve(__dirname, "../src/Antd_IconName.re"),
      reFile({
        icons: resultIcons,
      })
    );
    writeFileSync(
      resolve(__dirname, "../src/Antd_IconName.rei"),
      reiFile({
        icons: resultIcons,
      })
    );

    console.log("Done !");
  } catch (error) {
    console.error(error);
  }
})();
