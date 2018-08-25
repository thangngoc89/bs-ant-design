# bs-ant-design

## Introduction

Bucklescript + ReasonReact binding for [Ant Design](https://ant.design) components. I write bindings when I needed them in my projects. If you find a component is missing, it's because I don't need it (yet).

Difference from [bs-antd](https://github.com/tiensonqin/bs-antd) : It uses the official recommended way for writing bindings and it doesn't work for me. I explained this in this [blog post](https://khoanguyen.me/writing-reason-react-bindings-the-right-way/)

I also attempted to rewrite the components when possible for a better integration.

## Installation

* With npm:

```
npm install --save bs-ant-design
```

* With yarn:

```
yarn add bs-ant-design
```

* Add `bs-ant-design` to `bs-dependencies` in `bsconfig.json`.
* You also need to set up your bundler to handle less files (This is a requirement from ant-design)

For webpack, you can do this:

```
npm install --save-dev less@^2.7.3 less-loader css-loader style-loader
```

(`less@^2.7.3` is the important bit)

Now add this to your webpack config:

```js
// webpack.config.js
module.exports = {
    ...
    module: {
        rules: [{
        test: /\.less$/,
        use: ["style-loader", "css-loader", "less-loader"]
    }]
}
};
```

## Usage

Please check [ant design's documentation for each component](https://ant.design/docs/react/introduce).

I tried to keep the API as close to the original JS API as possible.

Some common patterns I used:

* string enums -> polymorphic variants
* function argument accepts different types: GDATs or `%identity` hack.

## Components

### Note:

* 🔗: a binding
* ✍️: rewrite in ReasonML
* 🆕: new helpers

### Implemented components

#### 🔗 AutoComplete

#### 🔗 Avatar

#### 🔗 Breadcrumb

#### 🔗 Button

#### 🔗 Divider

#### 🔗 Grid

#### 🔗 Input

#### 🔗 Select

#### 🔗 Steps

Usage:

* Single gutter size in pixels:

```reason
open Antd.Grid;

<Row gutter=Row.SingleGutterInPx(4) align=`top>
    <Col span=12 xs=Col.FullColSize(makeColSize(~span=5,()))>  
        (ReasonReact.stringToElement("A"))
    </Col>
    <Col span=8 xs=Col.SingleColSize(4)>  
        (ReasonReact.stringToElement("B"))
    </Col>
</Row>
```

* Responsive gutter:

```reason
open Antd.Grid;

<Row gutter=Row.ResponsiveBreakpoints(makeGutterBreakpoints(~sm=5, ()))>
    <Col span=8>  
        (ReasonReact.stringToElement("A"))
    </Col>
    <Col span=8>  
        (ReasonReact.stringToElement("B"))
    </Col>
    <Col span=8>  
        (ReasonReact.stringToElement("C"))
    </Col>
</Row>
```

#### ✍️ Icon

This uses IconName

#### ️🆕 IconName

Typesafe way (only way) to access icon's name

#### 🔗 Layout

#### 🔗 Menu

#### 🔗 Radio

#### 🔗 Spin

---

## Contributions

All contributions are welcomed.

## LICENSE

MIT
