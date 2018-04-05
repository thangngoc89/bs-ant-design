open Antd_Helpers;

[%bs.raw {|require("antd/lib/card/style")|}];

[@bs.module] external reactClass : ReasonReact.reactClass = "antd/lib/card";

type tab = {
  .
  "key": string,
  "tab": string,
};

[@bs.obj]
external makeProps :
  (
    ~actions: array(ReasonReact.reactElement)=?,
    ~bodyStyle: ReactDOMRe.Style.t=?,
    ~bordered: Js.boolean=?,
    ~cover: ReasonReact.reactElement=?,
    ~extra: ReasonReact.reactElement=?,
    ~hoverable: Js.boolean=?,
    ~loading: Js.boolean=?,
    ~tabList: array(tab)=?,
    ~activeTabKey: string=?,
    ~defaultActiveTabKey: string=?,
    ~title: ReasonReact.reactElement=?,
    ~type_: string=?,
    ~onTabChange: string => unit=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~actions=?,
      ~bodyStyle=?,
      ~bordered=?,
      ~cover=?,
      ~extra=?,
      ~hoverable=?,
      ~loading=?,
      ~tabList=?,
      ~activeTabKey=?,
      ~defaultActiveTabKey=?,
      ~title=?,
      ~type_=?,
      ~onTabChange=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~actions?,
        ~bodyStyle?,
        ~bordered=?Js.Option.map((. b) => from_bool(b), bordered),
        ~cover?,
        ~extra?,
        ~hoverable=?Js.Option.map((. b) => from_bool(b), hoverable),
        ~loading=?Js.Option.map((. b) => from_bool(b), loading),
        ~tabList?,
        ~activeTabKey?,
        ~defaultActiveTabKey?,
        ~title?,
        ~type_?,
        ~onTabChange?,
        (),
      ),
    children,
  );

module Grid = {
  [@bs.module "antd/lib/card"]
  external reactClass : ReasonReact.reactClass = "Grid";
  [@bs.obj]
  external makeProps :
    (~className: string=?, ~style: ReactDOMRe.Style.t=?, unit) => _ =
    "";
  let make = (~className=?, ~style=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~className?, ~style?, ()),
      children,
    );
};

module Meta = {
  [@bs.module "antd/lib/card"]
  external reactClass : ReasonReact.reactClass = "Meta";
  [@bs.obj]
  external makeProps :
    (
      ~avatar: ReasonReact.reactElement=?,
      ~className: string=?,
      ~description: ReasonReact.reactElement=?,
      ~style: ReactDOMRe.style=?,
      ~title: ReasonReact.reactElement=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (~avatar=?, ~className=?, ~description=?, ~style=?, ~title=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(~avatar?, ~className?, ~description?, ~style?, ~title?, ()),
      children,
    );
};