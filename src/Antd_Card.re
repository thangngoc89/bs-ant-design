[@bs.module] external card: ReasonReact.reactClass = "antd/lib/card";

[%bs.raw {|require("antd/lib/card/style")|}];

[@bs.deriving jsConverter]
type size = [ | `default | `small];

[@bs.deriving jsConverter]
type cardType = [ | `inner];

[@bs.deriving jsConverter]
type cardTabListType = {
  key: string,
  tab: ReasonReact.reactElement,
  disabled: bool,
};

[@bs.obj]
external makeProps:
  (
    ~prefixCls: string=?,
    ~title: ReasonReact.reactElement=?,
    ~extra: ReasonReact.reactElement=?,
    ~bordered: bool=?,
    ~headStyle: ReactDOMRe.Style.t=?,
    ~bodyStyle: ReactDOMRe.Style.t=?,
    ~style: ReactDOMRe.Style.t=?,
    ~loading: bool=?,
    ~noHovering: bool=?,
    ~hoverable: bool=?,
    ~children_: ReasonReact.reactElement=?,
    ~id: string=?,
    ~className: string=?,
    ~size: string=?,
    ~cardType: string=?,
    ~cover: ReasonReact.reactElement=?,
    ~actions: Js.Array.t(ReasonReact.reactElement)=?,
    ~tabList: Js.Array.t(Js.t({..}))=?,
    ~onTabChange: string => unit=?,
    ~activeTabKey: string=?,
    ~defaultActiveTabKey: string=?,
    unit
  ) =>
  _ =
  "";
/** 设置 card 需要监听其滚动事件的元素，值为一个返回对应 DOM 元素的函数 */
/* target?: () => Window | HTMLElement | null; */

let make =
    (
      ~prefixCls=?,
      ~title=?,
      ~extra=?,
      ~bordered=?,
      ~headStyle=?,
      ~bodyStyle=?,
      ~style=?,
      ~loading=?,
      ~noHovering=?,
      ~hoverable=?,
      ~children_=?,
      ~id=?,
      ~className=?,
      ~size=?,
      ~cardType=?,
      ~cover=?,
      ~actions=?,
      ~tabList=?,
      ~onTabChange=?,
      ~activeTabKey=?,
      ~defaultActiveTabKey=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=card,
    ~props=
      makeProps(
        ~prefixCls?,
        ~title?,
        ~extra?,
        ~bordered?,
        ~headStyle?,
        ~bodyStyle?,
        ~style?,
        ~loading?,
        ~noHovering?,
        ~hoverable?,
        ~children_?,
        ~id?,
        ~className?,
        ~size?,
        ~cardType=?Js.Option.map((. b) => cardTypeToJs(b), cardType),
        ~cover?,
        ~actions?,
        ~tabList?,
        ~onTabChange?,
        ~activeTabKey?,
        ~defaultActiveTabKey?,
        (),
      ),
    children,
  );